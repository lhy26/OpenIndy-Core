#ifndef SCALARENTITYTEMPERATURE_H
#define SCALARENTITYTEMPERATURE_H

#include <QObject>
#include <QtXml>

#include "geometry.h"

namespace oi{

/*!
 * \brief The ScalarEntityTemperature class
 */
class OI_CORE_EXPORT ScalarEntityTemperature : public Geometry
{
    Q_OBJECT

public:
    ScalarEntityTemperature(const bool &isNominal, QObject *parent = 0);
    ScalarEntityTemperature(const bool &isNominal, const double &temperature, QObject *parent = 0);

    ScalarEntityTemperature(const ScalarEntityTemperature &copy, QObject *parent = 0);

    ScalarEntityTemperature &operator=(const ScalarEntityTemperature &copy);

    ~ScalarEntityTemperature();

    //########################################
    //order of unknown parameters (Qxx-matrix)
    //########################################

    enum TemperatureUnknowns{
        unknownTemperature = 0
    };

    //#################################
    //get or set temperature parameters
    //#################################

    const double &getTemperature() const;

    void setTemperature(const double &temperature);

    //#############################
    //get or set unknown parameters
    //#############################

    virtual QMap<GeometryParameters, QString> getUnknownParameters(const QMap<DimensionType, UnitType> &displayUnits,
                                                          const QMap<DimensionType, int> &displayDigits) const;
    virtual void setUnknownParameters(const QMap<GeometryParameters, double> &parameters);

    //###########################
    //reexecute the function list
    //###########################

    void recalc();

    //#################
    //save and load XML
    //#################

    QDomElement toOpenIndyXML(QDomDocument &xmlDoc) const;
    bool fromOpenIndyXML(QDomElement &xmlElem);

    //###############
    //display methods
    //###############

    QString getDisplayTemperature(const UnitType &type, const int &digits, const bool &showDiff = false) const;

private:

    //######################
    //temperature attributes
    //######################

    double temperature;

};

}

#endif // SCALARENTITYTEMPERATURE_H
