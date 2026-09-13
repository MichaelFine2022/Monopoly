#pragma once

class Player;
class Space {
    private:
        const char *name;
        
    public:
        Space();
        Space(const char *name);
        virtual void handleLanding(Player *, Interface* display) {};
        const char *getName() const;
        virtual ~Space();
};