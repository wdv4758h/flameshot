// Copyright 2017 Alejandro Sirgo Rica
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

//#include "src/capture/tools/capturetool.h"
#include "capturemodification.h"
#include "src/capture/tools/toolfactory.h"
#include "src/capture/tools/capturetool.h"
#include <QColor>

// CaptureModification is a single modification in the screenshot drawn
// by the user.

CaptureModification::CaptureModification(
        const CaptureButton::ButtonType t,
        const QPoint &p,
        const QColor &c,
        QObject *parent) :
    QObject(parent),
    m_color(c),
    m_type(t)
{
    m_tool = ToolFactory().CreateTool(t, this);
    m_coords.append(p);
    if (m_tool->isSelectable()) {
        m_coords.append(p);
    }
}

CaptureButton::ButtonType CaptureModification::getType() const {
    return m_type;
}

QColor CaptureModification::getColor() const {
    return m_color;
}

QVector<QPoint> CaptureModification::getPoints() const {
    return m_coords;
}

CaptureTool* CaptureModification::getTool() const{
    return m_tool;
}

// addPoint adds a point to the vector of points
void CaptureModification::addPoint(const QPoint p) {
    if(m_tool->getToolType() == CaptureTool::TYPE_LINE_DRAWER) {
        m_coords[1] = p;
    } else {
        m_coords.append(p);
    }
}
