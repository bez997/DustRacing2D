// This file is part of Dust Rallycross (DustRAC).
// Copyright (C) 2011 Jussi Lind <jussi.lind@iki.fi>
//
// DustRAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// DustRAC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DustRAC. If not, see <http://www.gnu.org/licenses/>.

#include "tracktilebase.h"
#include "trackdata.h"

TrackTileBase::TrackTileBase(TrackData * trackData,
                             QPointF location, QPoint matrixLocation,
                             const QString & type)
: m_routeIndex(-1)
, m_tileType(type)
, m_location(location)
, m_matrixLocation(matrixLocation)
, m_trackData(trackData)
, m_routeDirection(TrackTileBase::RD_NONE)
, m_profile(TrackTileBase::TP_FLAT)
{
}

QPointF TrackTileBase::location() const
{
    return m_location;
}

QPoint TrackTileBase::matrixLocation() const
{
    return m_matrixLocation;
}

void TrackTileBase::setRouteIndex(int index)
{
    m_routeIndex = index;
}

int TrackTileBase::routeIndex() const
{
    return m_routeIndex;
}

void TrackTileBase::setTileType(const QString & type)
{
    if (type != m_tileType)
    {
        m_tileType = type;
    }
}

const QString & TrackTileBase::tileType() const
{
    return m_tileType;
}

void TrackTileBase::setRouteDirection(TrackTileBase::RouteDirection direction)
{
    m_routeDirection = direction;
}

TrackTileBase::RouteDirection TrackTileBase::routeDirection() const
{
    return m_routeDirection;
}

TrackData * TrackTileBase::trackData() const
{
    return m_trackData;
}

void TrackTileBase::setProfile(TrackTileBase::TileProfile profile)
{
    m_profile = profile;
}

TrackTileBase::TileProfile TrackTileBase::profile() const
{
    return m_profile;
}

TrackTileBase::~TrackTileBase()
{
}