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

#include "copytool.h"
#include <QPainter>

CopyTool::CopyTool(QObject *parent) : CaptureTool(parent) {

}

bool CopyTool::isSelectable() {
    return false;
}

QString CopyTool::getIconName() {
    return "content-copy.png";
}

QString CopyTool::getName() {
    return tr("Copy");
}

QString CopyTool::getDescription() {
    return tr("Copies the selecion into the clipboard");
}

CaptureTool::ToolWorkType CopyTool::getToolType() {
    return TYPE_WORKER;
}

void CopyTool::processImage(
        QPainter &painter,
        const QVector<QPoint> &points,
        const QColor &color)
{
    Q_UNUSED(painter);
    Q_UNUSED(points);
    Q_UNUSED(color);
}

void CopyTool::onPressed() {
    Q_EMIT requestAction(REQ_TO_CLIPBOARD);
    Q_EMIT requestAction(REQ_CLOSE_GUI);
}
