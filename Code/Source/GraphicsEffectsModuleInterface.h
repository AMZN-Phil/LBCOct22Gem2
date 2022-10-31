
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <Clients/GraphicsEffectsSystemComponent.h>

namespace GraphicsEffects
{
    class GraphicsEffectsModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(GraphicsEffectsModuleInterface, "{903381DE-0A6A-4C7A-B61B-2A657C8FBBFD}", AZ::Module);
        AZ_CLASS_ALLOCATOR(GraphicsEffectsModuleInterface, AZ::SystemAllocator, 0);

        GraphicsEffectsModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                GraphicsEffectsSystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<GraphicsEffectsSystemComponent>(),
            };
        }
    };
}// namespace GraphicsEffects
