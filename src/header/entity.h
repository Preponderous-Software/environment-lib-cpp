#ifndef Entity_h
#define Entity_h

#include <string>

namespace envlibcpp {

    // @author Daniel McCoy Stephenson
    // @since August 26th, 2022
    class Entity {
        public:
            Entity(int entityId, std::string entityName);
            int getId();
            std::string getName();
            int getEnvironmentId();
            int getGridId();
            int getLocationId();
            void setName(std::string newName);
            void setEnvironmentId(int id);
            void setGridId(int id);
            void setLocationId(int id);
        private:
            int id;
            std::string name;
            int environmentId;
            int gridId;
            int locationId;
    };
}

#endif