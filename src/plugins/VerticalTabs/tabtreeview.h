/* ============================================================
* VerticalTabs plugin for QupZilla
* Copyright (C) 2018 David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#pragma once

#include <QTreeView>

#include "qzcommon.h"

class TabTreeDelegate;

class QUPZILLA_EXPORT TabTreeView : public QTreeView
{
    Q_OBJECT

public:
    explicit TabTreeView(QWidget *parent = 0);

    // In TabBar order
    bool areTabsInOrder() const;
    void setTabsInOrder(bool enable);

private:
    void drawBranches(QPainter *painter, const QRect &rect, const QModelIndex &index) const override;
    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>()) override;

    bool viewportEvent(QEvent *event) override;

    enum DelegateButton {
        NoButton,
        ExpandButton,
        AudioButton,
        CloseButton
    };

    DelegateButton buttonAt(const QPoint &pos, const QModelIndex &index) const;

    TabTreeDelegate *m_delegate;
    DelegateButton m_pressedButton = NoButton;
    QModelIndex m_pressedIndex;
    bool m_tabsInOrder = false;
};
