/***************************************************************************
 *                                                                         *
 *   This file is part of the Fotowall project,                            *
 *       http://www.enricoros.com/opensource/fotowall                      *
 *                                                                         *
 *   Copyright (C) 2009 by Enrico Ros <enrico.ros@gmail.com>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef __Stacker_h__
#define __Stacker_h__

#include <QObject>
#include <QList>

namespace PlugGui {

    class Container;
    class AbstractAppliance;

    class Stacker : public QObject
    {
        Q_OBJECT
        public:
            Stacker();
            ~Stacker();

            // set container (runtime changeable)
            void setContainer(Container * container);
            Container * container() const;

            // appliance stacking operations
            void stackAppliance(AbstractAppliance * appliance);
            QList<AbstractAppliance *> stackedAppliances() const;
            AbstractAppliance * currentAppliance() const;
            bool currentApplianceCommand(int command);
            void popAppliance();
            void dropStackAfter(int index);
            void clearAppliances();

        Q_SIGNALS:
            // notify (ex. on a push/pop operation)
            void structureChanged();

        private:
            Container * m_container;
            QList<AbstractAppliance *> m_appliances;
            bool m_disableNotify;
    };

}

#endif