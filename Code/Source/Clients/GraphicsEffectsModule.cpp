

#include <GraphicsEffectsModuleInterface.h>
#include "GraphicsEffectsSystemComponent.h"

namespace GraphicsEffects
{
    class GraphicsEffectsModule
        : public GraphicsEffectsModuleInterface
    {
    public:
        AZ_RTTI(GraphicsEffectsModule, "{BC48AEA8-031B-40A9-8F8A-DD9061E62B7A}", GraphicsEffectsModuleInterface);
        AZ_CLASS_ALLOCATOR(GraphicsEffectsModule, AZ::SystemAllocator, 0);
    };
}// namespace GraphicsEffects

AZ_DECLARE_MODULE_CLASS(Gem_GraphicsEffects, GraphicsEffects::GraphicsEffectsModule)
