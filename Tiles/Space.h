#pragma once


class Space {
    private:
        char *name;
        
    public:
        Space();
        Space(char *name);
        void handleLanding(Player *);
        char *getName() const;
        virtual ~Space();
};