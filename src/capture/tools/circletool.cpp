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

#include "circletool.h"
#include <QPainter>

CircleTool::CircleTool(QObject *parent) : CaptureTool(parent) {

}

bool CircleTool::isSelectable() {
    return true;
}

QString CircleTool::getIconName() {
    return "circle-outline.png";
}

QString CircleTool::getName() {
    return tr("Circle");
}

QString CircleTool::getDescription() {
    return tr("Sets the Circle as the paint tool");
}

CaptureTool::ToolWorkType CircleTool::getToolType() {
    return TYPE_LINE_DRAWER;
}

void CircleTool::processImage(
        QPainter &painter,
        const QVector<QPoint> &points,
        const QColor &color)
{
    painter.setPen(QPen(color, 2));
    painter.drawEllipse(QRect(points[0], points[1]));
}

void CircleTool::onPressed() {
}
