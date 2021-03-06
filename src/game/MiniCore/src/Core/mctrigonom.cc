// This file belongs to the "MiniCore" game engine.
// Copyright (C) 2009 Jussi Lind <jussi.lind@iki.fi>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA  02110-1301, USA.
//

#include "mctrigonom.hh"
#include "mccast.hh"

#include <cmath>
#include <vector>

namespace
{
    const unsigned int LutSize = 7200;
    const float PI = 3.1415926536f;
}

//! Implementation class for MCTrigonom
class MCTrigonomImpl
{
public:
    MCTrigonomImpl();

private:
    std::vector<float> m_sin;
    std::vector<float> m_cos;
    friend class MCTrigonom;
};

std::unique_ptr<MCTrigonomImpl> const MCTrigonom::m_pImpl(new MCTrigonomImpl);

MCTrigonomImpl::MCTrigonomImpl()
: m_sin(LutSize, 0)
, m_cos(LutSize, 0)
{
    for (unsigned int i = 0; i < LutSize; i++) {
        MCTrigonomImpl::m_sin.at(i) =
            std::sin(MCTrigonom::degToRad(TO_FLOAT(i) / 10.0f - 3600));
        MCTrigonomImpl::m_cos.at(i) =
            std::cos(MCTrigonom::degToRad(TO_FLOAT(i) / 10.0f - 3600));
    }
}

float MCTrigonom::degToRad(float angle)
{
    static const float DegToRad(PI / 180.0f);
    return angle * DegToRad;
}

float MCTrigonom::radToDeg(float angle)
{
    static const float RadToDeg(180.0f / PI);
    return angle * RadToDeg;
}

float MCTrigonom::sin(float angle)
{
    const int index = static_cast<int>(angle * 10.0f) + 3600;
    if (index >= 0 && index < static_cast<int>(LutSize))
    {
        return m_pImpl->m_sin[index];
    }
    return std::sin(degToRad(angle));
}

float MCTrigonom::cos(float angle)
{
    const int index = static_cast<int>(angle * 10.0f) + 3600;
    if (index >= 0 && index < static_cast<int>(LutSize))
    {
        return m_pImpl->m_cos[index];
    }
    return std::cos(degToRad(angle));
}
