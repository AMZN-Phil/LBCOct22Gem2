
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/GraphicsEffectsSystemComponent.h>

namespace GraphicsEffects
{
    /// System component for GraphicsEffects editor
    class GraphicsEffectsEditorSystemComponent
        : public GraphicsEffectsSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = GraphicsEffectsSystemComponent;
    public:
        AZ_COMPONENT(GraphicsEffectsEditorSystemComponent, "{6860A493-367C-4FF3-B983-989B40A90E3C}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        GraphicsEffectsEditorSystemComponent();
        ~GraphicsEffectsEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace GraphicsEffects
