
#include <GraphicsEffectsModuleInterface.h>
#include "GraphicsEffectsEditorSystemComponent.h"

namespace GraphicsEffects
{
    class GraphicsEffectsEditorModule
        : public GraphicsEffectsModuleInterface
    {
    public:
        AZ_RTTI(GraphicsEffectsEditorModule, "{BC48AEA8-031B-40A9-8F8A-DD9061E62B7A}", GraphicsEffectsModuleInterface);
        AZ_CLASS_ALLOCATOR(GraphicsEffectsEditorModule, AZ::SystemAllocator, 0);

        GraphicsEffectsEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                GraphicsEffectsEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<GraphicsEffectsEditorSystemComponent>(),
            };
        }
    };
}// namespace GraphicsEffects

AZ_DECLARE_MODULE_CLASS(Gem_GraphicsEffects, GraphicsEffects::GraphicsEffectsEditorModule)
