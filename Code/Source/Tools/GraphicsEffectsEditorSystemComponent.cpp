
#include <AzCore/Serialization/SerializeContext.h>
#include "GraphicsEffectsEditorSystemComponent.h"

namespace GraphicsEffects
{
    void GraphicsEffectsEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<GraphicsEffectsEditorSystemComponent, GraphicsEffectsSystemComponent>()
                ->Version(0);
        }
    }

    GraphicsEffectsEditorSystemComponent::GraphicsEffectsEditorSystemComponent() = default;

    GraphicsEffectsEditorSystemComponent::~GraphicsEffectsEditorSystemComponent() = default;

    void GraphicsEffectsEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("GraphicsEffectsEditorService"));
    }

    void GraphicsEffectsEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("GraphicsEffectsEditorService"));
    }

    void GraphicsEffectsEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void GraphicsEffectsEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void GraphicsEffectsEditorSystemComponent::Activate()
    {
        GraphicsEffectsSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void GraphicsEffectsEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        GraphicsEffectsSystemComponent::Deactivate();
    }

} // namespace GraphicsEffects
