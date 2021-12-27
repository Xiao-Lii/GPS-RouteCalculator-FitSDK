//
// Created by Lee on 12/26/2021.
//

#ifndef GPS_ROUTECALCULATOR_FITSDK_DECODE_H
#define GPS_ROUTECALCULATOR_FITSDK_DECODE_H

#include <fstream>
#include <iostream>

#include "fit_decode.hpp"
#include "fit_mesg_broadcaster.hpp"
#include "fit_developer_field_description.hpp"

class Listener
        : public fit::FileIdMesgListener
        , public fit::UserProfileMesgListener
        , public fit::MonitoringMesgListener
        , public fit::DeviceInfoMesgListener
        , public fit::MesgListener
        , public fit::DeveloperFieldDescriptionListener
        , public fit::RecordMesgListener
{
public:
    static void PrintValue(const fit::FieldBase& field);
    void OnMesg(fit::Mesg& mesg);
    void OnMesg(fit::FileIdMesg& mesg);
    void OnMesg(fit::UserProfileMesg& mesg);
    void OnMesg(fit::DeviceInfoMesg& mesg);
    void OnMesg(fit::MonitoringMesg& mesg);
    static void PrintOverrideValues( const fit::Mesg& mesg, FIT_UINT8 fieldNum );
    void OnMesg( fit::RecordMesg& record ) override
    void OnDeveloperFieldDescription( const fit::DeveloperFieldDescription& desc ) override

};

#endif //GPS_ROUTECALCULATOR_FITSDK_DECODE_H
