#include "walletmodels.h"

namespace exodus {

// SigmaMintChainState Implementation.

SigmaMintChainState::SigmaMintChainState() noexcept : block(-1), group(0), index(0)
{
}

SigmaMintChainState::SigmaMintChainState(int block, SigmaMintGroup group, SigmaMintIndex index) noexcept :
    block(block),
    group(group),
    index(index)
{
}

bool SigmaMintChainState::operator==(const SigmaMintChainState& other) const noexcept
{
    return block == other.block && group == other.group && index == other.index;
}

bool SigmaMintChainState::operator!=(const SigmaMintChainState& other) const noexcept
{
    return !(*this == other);
}

void SigmaMintChainState::Clear() noexcept
{
    block = -1;
    group = 0;
    index = 0;
}

// SigmaMint Implementation.

SigmaMint::SigmaMint() : property(0), denomination(0)
{
}

SigmaMint::SigmaMint(PropertyId property, SigmaDenomination denomination) :
    property(property),
    denomination(denomination)
{
    key.Generate();
}

bool SigmaMint::operator==(const SigmaMint& other) const
{
    return property == other.property &&
           denomination == other.denomination &&
           chainState == other.chainState &&
           key == other.key &&
           spentTx == other.spentTx;
}

bool SigmaMint::operator!=(const SigmaMint& other) const
{
    return !(*this == other);
}

// SigmaMintId Implementation.

SigmaMintId::SigmaMintId() : property(0), denomination(0)
{
}

SigmaMintId::SigmaMintId(const SigmaMint& mint, const SigmaParams& params) :
    SigmaMintId(mint.property, mint.denomination, SigmaPublicKey(mint.key, params))
{
}

SigmaMintId::SigmaMintId(PropertyId property, SigmaDenomination denomination, const SigmaPublicKey& key) :
    property(property),
    denomination(denomination),
    key(key)
{
}

bool SigmaMintId::operator==(const SigmaMintId& other) const
{
    return property == other.property && denomination == other.denomination && key == other.key;
}

bool SigmaMintId::operator!=(const SigmaMintId& other) const
{
    return !(*this == other);
}

// SigmaSpend Implementation.

SigmaSpend::SigmaSpend(const SigmaMintId& mint, SigmaMintGroup group, size_t groupSize, const SigmaProof& proof) :
    mint(mint),
    group(group),
    groupSize(groupSize),
    proof(proof)
{
}

} // namespace exodus