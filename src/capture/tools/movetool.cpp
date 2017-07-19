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

#include "movetool.h"
#include <QPainter>

MoveTool::MoveTool(QObject *parent) : CaptureTool(parent) {

}

bool MoveTool::isSelectable() {
    return false;
}

QString MoveTool::getIconName() {
    return "cursor-move.png";
}

QString MoveTool::getName() {
    return tr("Move");
}

QString MoveTool::getDescription() {
    return tr("Move the selection area");
}

CaptureTool::ToolWorkType MoveTool::getToolType() {
    return TYPE_WORKER;
}

void MoveTool::processImage(
        QPainter &painter,
        const QVector<QPoint> &points,
        const QColor &color)
{
    Q_UNUSED(painter);
    Q_UNUSED(points);
    Q_UNUSED(color);
}

void MoveTool::onPressed() {
    Q_EMIT requestAction(REQ_MOVE_MODE);
}
