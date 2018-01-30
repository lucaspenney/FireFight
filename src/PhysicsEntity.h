
#include "Entity.h"

#include "Bounds.h"

class PhysicsEntity : public Entity {
    PhysicsEntity(Bounds b);
    void update(Game* game);
private:
    Bounds bounds;
};
