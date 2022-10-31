
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace GraphicsEffects
{
    class GraphicsEffectsRequests
    {
    public:
        AZ_RTTI(GraphicsEffectsRequests, "{78E290BE-7AB6-4A4F-9E5E-61A5915FA7B7}");
        virtual ~GraphicsEffectsRequests() = default;
        // Put your public methods here
    };
    
    class GraphicsEffectsBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using GraphicsEffectsRequestBus = AZ::EBus<GraphicsEffectsRequests, GraphicsEffectsBusTraits>;
    using GraphicsEffectsInterface = AZ::Interface<GraphicsEffectsRequests>;

} // namespace GraphicsEffects
