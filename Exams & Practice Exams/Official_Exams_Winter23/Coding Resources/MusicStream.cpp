#include <iostream>
#include <vector>
using namespace std;

class User;

class Media {
public:
    virtual double getPoints() const = 0;
    virtual void addToUser(User* user) = 0;
};

class User {
public:
    User() : totalPoints(0) {}

    bool isPositive() {
        return totalPoints > 0.0;
    }

    void addToHeard(Media* media) {
        heard.push_back(media);
        media->addToUser(this);
    }

    double getTotalPoints() const {
        return totalPoints;
    }

    void addPoints(double points) {
        totalPoints += points;
    }

private:
    vector<Media*> heard;
    double totalPoints;
};

class Song : public Media {
public:
    Song(int duration) : duration(duration) {}

    double getPoints() const {
        return -static_cast<double>(duration) / 300.0;
    }

    void addToUser(User* user) {
        user->addPoints(getPoints());
    }

private:
    int duration;
};

class Advertisement : public Media {
public:
    double getPoints() const {
        return 1.0;
    }

    void addToUser(User* user) {
        user->addPoints(getPoints());
    }
};

int main() {
    // Usage example
    User user;
    Song song1(300);
    Song song2(600);
    Advertisement ad;

    user.addToHeard(&song1);
    user.addToHeard(&ad);
    user.addToHeard(&song2);

    cout << "Total points: " << user.getTotalPoints() << endl;
    cout << "Is Positive: " << user.isPositive() << endl;

    return 0;
}