#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

const int SANDBOX_ROWS = 20;
const int SANDBOX_COLS = 20;

struct Position {
    int row;
    int col;
};

class Sandbox;

class Bug {
public:
    Bug(const Position& pos);
    Bug();
    virtual ~Bug();
    Position getPosition() const;
    void setPosition(const Position& pos);
    virtual char getType() const =0;
    virtual void move(Sandbox& sandbox) =0;
    virtual void breed(Sandbox& sandbox) =0;
    virtual void starve(Sandbox& sandbox) =0;
    void die(Sandbox& sandbox) const;
    virtual void print(ostream& outs) const =0;
    friend ostream& operator <<(ostream& outs, const Bug& bug);

private:
    Position position;
};

class Ant : public Bug {
public:
    Ant(const Position& pos);
    Ant();
    virtual ~Ant();
    virtual char getType() const;
    virtual void move(Sandbox& sandbox);
    virtual void breed(Sandbox& sandbox);
    virtual void starve(Sandbox& sandbox);
    virtual void print(ostream& outs) const;

private:
    int breedTimer;
};

class Doodlebug : public Bug {
public:
    Doodlebug(const Position& pos);
    Doodlebug();
    virtual ~Doodlebug();
    virtual char getType() const;
    virtual void move(Sandbox& sandbox);
    virtual void breed(Sandbox& sandbox);
    virtual void starve(Sandbox& sandbox);
    virtual void print(ostream& outs) const;

private:
    int breedTimer;
    int starveTimer;
    vector<Position> findFood(Sandbox& sandbox);
};

class Sandbox {
public:
    Sandbox();
    ~Sandbox();
    int getPreyBreedTotal() const;
    int getPreyDeathTotal() const;
    int getPredatorBreedTotal() const;
    int getPredatorConsumeTotal() const;
    int getPredatorDeathTotal() const;
    void setPreyBreedTotal(int newTotal);
    void setPreyDeathTotal(int newTotal);
    void setPredatorBreedTotal(int newTotal);
    void setPredatorConsumeTotal(int newTotal);
    void setPredatorDeathTotal(int newTotal);
    bool isCellAvailable(const Position& pos) const;
    vector<Position> getAvailableAdjacentCells(const Position& pos) const;
    Bug* getBug(const Position& pos) const;
    void setBug(const Position& pos, Bug* bugPtr);
    void moveBug(const Position& pos, const Position& nextPos);
    void removeBug(const Bug* bugPtr);
    void simulateOneTimeStep();
    void display() const;
    void intro() const;

private:
    Bug* grid[SANDBOX_ROWS][SANDBOX_COLS];
    int preyBreedTotal;
    int preyDeathTotal;
    int predatorBreedTotal;
    int predatorConsumeTotal;
    int predatorDeathTotal;
};

int main () {

    srand(time(0));

    Sandbox sandbox;
    int timeUnit = 0;
    bool keepGoing = true;
    string input;

    while (keepGoing) {
        cout << endl;
        cout << "Sandbox snapshot at time = " << timeUnit << ": " << endl << endl;


        sandbox.display();

        cout << endl;
        cout << "Press enter to continue or enter 1 to exit the simulation: ";
        
        input = cin.get();
        if (input == "1"){
            keepGoing = false;
            cout << endl;
            cout << "You have exited the simulation";
            exit(1);
        } else {
            sandbox.simulateOneTimeStep();
            timeUnit++;
        }
        
    }

    return 0;
}


//Bug class - an abstract class due to the pure virtuals declared

Bug::Bug(const Position& pos) : position(pos) {}

Bug::Bug() {}

Bug::~Bug() {}

Position Bug::getPosition() const {
    return position;
}

void Bug::setPosition(const Position& pos){
    position.row = pos.row;
    position.col = pos.col;
}

void Bug::die(Sandbox& sandbox) const{
    sandbox.removeBug(this);
}

ostream& operator <<(ostream& outs , const Bug& bug) {
    bug.print(outs);

    return outs;
}

//Ant Class - derives from the Bug Class

Ant::Ant(const Position& pos) : Bug(pos), breedTimer(0) {}

Ant::Ant() : Bug(), breedTimer(0) {}

Ant::~Ant() {}

char Ant::getType() const {
    return 'A';
}

void Ant::move(Sandbox& sandbox){
    int direction = rand() % 4;
    Position currPos = getPosition();
    Position nextPos = currPos;

    if (direction == 0){
        nextPos.row--;
    } else if (direction == 1){
        nextPos.row++;
    } else if (direction == 2){
        nextPos.col--;
    } else if (direction == 3){
        nextPos.col++;
    }

    if (sandbox.isCellAvailable(nextPos)){
        sandbox.moveBug(currPos, nextPos);
    }

    breedTimer++;
}

void Ant::breed(Sandbox& sandbox){
    if (breedTimer < 3){
        return;
    }

    Position currPos = getPosition();
    vector<Position> unoccupiedAdjCells = sandbox.getAvailableAdjacentCells(currPos);

    if(!unoccupiedAdjCells.empty()){
        int random = rand() % unoccupiedAdjCells.size();
        Position newAntPos = unoccupiedAdjCells[random];

        sandbox.setBug(newAntPos, new Ant);
        sandbox.setPreyBreedTotal(sandbox.getPreyBreedTotal() + 1);
    }

    breedTimer = 0;
}

void Ant::starve(Sandbox& sandbox) {
    //Only here because we made starve in the parent Bug class pure virtual
}

void Ant::print(ostream& outs) const {
    outs << 'o';
}

//Doodlebug class - derives from the Bug class

Doodlebug::Doodlebug(const Position& pos) : Bug(pos), breedTimer(0), starveTimer(0) {}

Doodlebug::Doodlebug() : Bug(), breedTimer(0), starveTimer(0) {} 

Doodlebug::~Doodlebug() {}

char Doodlebug::getType() const {
    return 'D';
}

void Doodlebug::move(Sandbox& sandbox) {
    Position currPos = getPosition();
    vector<Position> adjFood = findFood(sandbox);

    if (!adjFood.empty()){
        int randomCellSelect = rand() % adjFood.size();
        Position tgtFoodPos = adjFood[randomCellSelect];

        sandbox.getBug(tgtFoodPos)->die(sandbox);
        sandbox.moveBug(currPos, tgtFoodPos);

        breedTimer++;
        starveTimer = 0;
        sandbox.setPreyDeathTotal(sandbox.getPreyDeathTotal() + 1);
        sandbox.setPredatorConsumeTotal(sandbox.getPredatorConsumeTotal() + 1);
    }

    else {
        int direction = rand() % 4;
        Position nextPos = currPos;

        if (direction == 0){
            nextPos.row--;
        } else if (direction == 1){
            nextPos.row++;
        } else if (direction == 2){
            nextPos.col--;
        } else if (direction == 3){
            nextPos.col++;
        } 


        if (sandbox.isCellAvailable(nextPos)){
            sandbox.moveBug(currPos, nextPos);
        }
    
        breedTimer++;
        starveTimer++;
    }    
}

void Doodlebug::breed(Sandbox& sandbox){
    if (breedTimer < 8){
        return;
    }

    Position currPos = getPosition();
    vector<Position> unoccupiedAdjCells = sandbox.getAvailableAdjacentCells(currPos);

    if (!unoccupiedAdjCells.empty()) {
        int randomCellSelect = rand() % unoccupiedAdjCells.size();
        Position newDoodlebugPos = unoccupiedAdjCells[randomCellSelect];

        sandbox.setBug(newDoodlebugPos, new Doodlebug);
        sandbox.setPredatorBreedTotal(sandbox.getPredatorBreedTotal() + 1);
    }

    breedTimer = 0;
}

void Doodlebug::starve(Sandbox& sandbox){
    if (starveTimer < 3){
        return;
    }

    die(sandbox);
    sandbox.setPredatorDeathTotal(sandbox.getPredatorDeathTotal() + 1);
}


void Doodlebug::print(ostream& outs) const {
    outs << 'X';
}

vector<Position> Doodlebug::findFood(Sandbox& sandbox){
    Position currPos = getPosition();
    vector<Position> adjFood;
    vector<Position> options = {
        {currPos.row - 1, currPos.col},
        {currPos.row + 1, currPos.col},
        {currPos.row, currPos.col - 1},
        {currPos.row, currPos.col + 1}
    };

    for (Position pos: options){
        Bug* bugPtr = sandbox.getBug(pos);

        if ((bugPtr != nullptr) && (bugPtr->getType() == 'A')) {
            adjFood.push_back(pos);
        }
    }

    return adjFood;
}


// builds the sandbox in which the game will occur

Sandbox::Sandbox() : preyBreedTotal(0), preyDeathTotal(0), predatorBreedTotal(0), predatorConsumeTotal(0), predatorDeathTotal(0) {
    intro();

    //Creates the original 20 x 20 plot of pointers pointing at nullptrs
    for (int i = 0; i < SANDBOX_ROWS; i++){
        for (int j = 0; j < SANDBOX_COLS; j++){
            grid[i][j] = nullptr;
        }
    }

    //Creates the original set of Doodlebugs on the sandbox
    for (int i = 0; i < 5; i++){
        int row = rand() % SANDBOX_ROWS;
        int col = rand() % SANDBOX_COLS;

        while(grid[row][col] != nullptr){
            row = rand() % SANDBOX_ROWS;
            col = rand() % SANDBOX_COLS;
        }

        Position temp;
        temp.row = row;
        temp.col = col;


        grid[row][col] = new Doodlebug(temp);
    }

    // Creates the original set of Ants on the sandbox
    for (int i = 0; i < 100; i++){
        int row = rand() % SANDBOX_ROWS;
        int col = rand() % SANDBOX_COLS;

        while(grid[row][col] != nullptr){
            row = rand() % SANDBOX_ROWS;
            col = rand() % SANDBOX_COLS;
        }

        Position temp2;
        temp2.row = row;
        temp2.col = col;

        grid[row][col] = new Ant(temp2);

    }

}

Sandbox::~Sandbox() {
    for (int i = 0; i < SANDBOX_ROWS; i++){
        for (int j = 0; i < SANDBOX_COLS; j++){
            if (grid[i][j] != nullptr){
                delete grid[i][j];
            }
        }
    }
}



int Sandbox::getPreyBreedTotal() const {
    return preyBreedTotal;
}

int Sandbox::getPreyDeathTotal() const {
    return preyDeathTotal;
}

int Sandbox::getPredatorBreedTotal() const {
    return predatorBreedTotal;
}

int Sandbox::getPredatorConsumeTotal() const {
    return predatorConsumeTotal;
}

int Sandbox::getPredatorDeathTotal() const {
    return predatorDeathTotal;
}

void Sandbox::setPreyBreedTotal(int newTotal){
    this->preyBreedTotal = newTotal;
}

void Sandbox::setPreyDeathTotal(int newTotal){
    this->preyDeathTotal = newTotal;
}

void Sandbox::setPredatorBreedTotal(int newTotal){
    this->predatorBreedTotal = newTotal;
}

void Sandbox::setPredatorConsumeTotal(int newTotal){
    this->predatorConsumeTotal = newTotal;
}

void Sandbox::setPredatorDeathTotal(int newTotal){
    this->predatorDeathTotal = newTotal;
}

bool Sandbox::isCellAvailable(const Position& pos) const {
    return (0 <= pos.row) && (pos.row < SANDBOX_ROWS) && (0 <= pos.col) && (pos.col < SANDBOX_COLS) && (grid[pos.row][pos.col] == nullptr);
}

vector<Position> Sandbox::getAvailableAdjacentCells(const Position& currPos) const {
    vector<Position> unoccupiedAdjCells;
    vector<Position> possibleCells = {
        {currPos.row - 1, currPos.col},
        {currPos.row + 1, currPos.col},
        {currPos.row, currPos.col - 1},
        {currPos.row, currPos.col + 1}
    };

    for (Position temp: possibleCells){
        if (isCellAvailable(temp)){
            unoccupiedAdjCells.push_back(temp);
        }
    }

    return unoccupiedAdjCells;
}

void Sandbox::simulateOneTimeStep() {
    vector<Bug*> antsVect;
    vector<Bug*> doodlebugsVect;


    for (int i = 0; i < SANDBOX_ROWS; i++){
        for (int j = 0; j < SANDBOX_COLS; j++){
            if ((grid[i][j] != nullptr) && (grid[i][j]->getType() == 'D')){
                doodlebugsVect.push_back(grid[i][j]);
            }

        }
    }
    
    for (Bug* doodlebug: doodlebugsVect){
        doodlebug->move(*this);
    }


    for (int i = 0; i < SANDBOX_ROWS; i++){
        for (int j = 0; j < SANDBOX_COLS; j++){
            if ((grid[i][j] != nullptr) && (grid[i][j]->getType() == 'A')){
                antsVect.push_back(grid[i][j]);
            }
        }
    }

    for (Bug* ant: antsVect){
        ant->move(*this);
    }

    for (Bug* doodlebug: doodlebugsVect){
        doodlebug->breed(*this);
    }

    for (Bug* doodlebug: doodlebugsVect){
        doodlebug->starve(*this);
    }

    for (Bug* ant: antsVect){
        ant->breed(*this);
    }

    cout << endl;
    cout << "End-Of-Round Totals Stats: " << endl << endl;
    cout << "Prey Breed Count: " << getPreyBreedTotal() << endl;
    cout << "Prey Death Count: " << getPreyDeathTotal() << endl;
    cout << "Predator Breed Count: " << getPredatorBreedTotal() << endl;
    cout << "Predator Death Count: " << getPredatorDeathTotal() << endl;
    cout << "Predator Consume Count: " << getPredatorConsumeTotal() << endl << endl;

    cout << "Prey Count: " << antsVect.size() << endl;
    cout << "Predators Count: " << doodlebugsVect.size() << endl;  

    if (doodlebugsVect.size() == 0){
        cout << endl;
        cout << "Game Over: Predators win, there are no longer prey"<< endl;
        exit(1);
    }

    if (antsVect.size() == 0){
        cout << endl;
        cout << "Game Over: Prey win, there are no longer predators" << endl;
        exit(1);
    }  

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

Bug* Sandbox::getBug(const Position& pos) const {
    if((0 <= pos.row) && (pos.row < SANDBOX_ROWS) && (0 <= pos.col) && (pos.col < SANDBOX_COLS)){
        return grid[pos.row][pos.col];
    } else {
        return nullptr;
    }
}

void Sandbox::setBug(const Position& pos, Bug* bugPtr){
    grid[pos.row][pos.col] = bugPtr;
    bugPtr->setPosition(pos);
}

void Sandbox::moveBug(const Position& currPos, const Position& nextPos){
    grid[nextPos.row][nextPos.col] = grid[currPos.row][currPos.col];
    grid[nextPos.row][nextPos.col]->setPosition(nextPos);
    grid[currPos.row][currPos.col] = nullptr;
}

void Sandbox::removeBug(const Bug *bugPtr){
    Position temp = bugPtr->getPosition();
    grid[temp.row][temp.col] = nullptr;
    delete bugPtr;

}

void Sandbox::display() const {
    for (int i = 0; i < SANDBOX_ROWS; i++){
        for (int j = 0; j < SANDBOX_COLS; j++){
            if (grid[i][j] == nullptr){
                cout << '-';
            } 
            else {
                cout << *grid[i][j];
            }

            cout << ' ';
        }
        cout << endl;
    }
}

void Sandbox::intro() const {
    cout << endl;
    cout << "Predator/Prey Simulation" << endl << endl;

    cout << "Prey Rules: " << endl;
    cout << "Movement: Prey move to one adjacent empty space per time unit"<< endl;
    cout << "Die: Prey die if a predator enters their space" << endl;
    cout << "Breed: Prey can breed and spawn a new prey in an adjacent empty space if they have survived for 3 time units" << endl << endl;

    cout << "Predator Rules: " << endl;
    cout << "Movement: Predators move to one adjacent space per time unit, prioritizing spaces with prey next to them" << endl;
    cout << "Die (Starve): Predators die if they have not eaten prey within 3 time units, when they do eat prey, thier starve counter resets in order to reflect their need for nutrition" << endl;
    cout << "Breed: Predators can breed and spawn a new predator in an adjacent empty space if they have survived for 8 time units" << endl << endl;

    cout << "The simulation ends when there are no longer any prey or predators left" << endl << endl;

    cout << "Starting Board: " << endl;
    cout << "Prey Amount: 100 " << endl;
    cout << "Predator Amount: 5 " << endl << endl;

    cout << "Simulation Legend: " << endl;
    cout << "Prey: o " << endl;
    cout << "Predator: X " << endl << endl;
}