
#include "GraphicsEffectsSystemComponent.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

namespace GraphicsEffects
{
    void GraphicsEffectsSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<GraphicsEffectsSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<GraphicsEffectsSystemComponent>("GraphicsEffects", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void GraphicsEffectsSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("GraphicsEffectsService"));
    }

    void GraphicsEffectsSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("GraphicsEffectsService"));
    }

    void GraphicsEffectsSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void GraphicsEffectsSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    GraphicsEffectsSystemComponent::GraphicsEffectsSystemComponent()
    {
        if (GraphicsEffectsInterface::Get() == nullptr)
        {
            GraphicsEffectsInterface::Register(this);
        }
    }

    GraphicsEffectsSystemComponent::~GraphicsEffectsSystemComponent()
    {
        if (GraphicsEffectsInterface::Get() == this)
        {
            GraphicsEffectsInterface::Unregister(this);
        }
    }

    void GraphicsEffectsSystemComponent::Init()
    {
    }

    void GraphicsEffectsSystemComponent::Activate()
    {
        GraphicsEffectsRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void GraphicsEffectsSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        GraphicsEffectsRequestBus::Handler::BusDisconnect();
    }

    void GraphicsEffectsSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace GraphicsEffects
