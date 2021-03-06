cmake_minimum_required(VERSION 3.21)
project(GPS-RouteCalculator-FitSDK)

set(CMAKE_CXX_STANDARD 11)

include_directories(cpp
        gpsFunctions.cpp)

add_executable(GPS-RouteCalculator-FitSDK
        main.cpp
        listener.cpp
        )

#cpp/fit.cpp
#cpp/fit.hpp
#cpp/fit_accelerometer_data_mesg.hpp
#cpp/fit_accelerometer_data_mesg_listener.hpp
#cpp/fit_accumulated_field.cpp
#cpp/fit_accumulated_field.hpp
#cpp/fit_accumulator.cpp
#cpp/fit_accumulator.hpp
#cpp/fit_activity_mesg.hpp
#cpp/fit_activity_mesg_listener.hpp
#cpp/fit_ant_channel_id_mesg.hpp
#cpp/fit_ant_channel_id_mesg_listener.hpp
#cpp/fit_ant_rx_mesg.hpp
#cpp/fit_ant_rx_mesg_listener.hpp
#cpp/fit_ant_tx_mesg.hpp
#cpp/fit_ant_tx_mesg_listener.hpp
#cpp/fit_aviation_attitude_mesg.hpp
#cpp/fit_aviation_attitude_mesg_listener.hpp
#cpp/fit_barometer_data_mesg.hpp
#cpp/fit_barometer_data_mesg_listener.hpp
#cpp/fit_bike_profile_mesg.hpp
#cpp/fit_bike_profile_mesg_listener.hpp
#cpp/fit_blood_pressure_mesg.hpp
#cpp/fit_blood_pressure_mesg_listener.hpp
#cpp/fit_buffer_encode.cpp
#cpp/fit_buffer_encode.hpp
#cpp/fit_buffered_mesg_broadcaster.cpp
#cpp/fit_buffered_mesg_broadcaster.hpp
#cpp/fit_buffered_record_mesg.hpp
#cpp/fit_buffered_record_mesg_broadcaster.cpp
#cpp/fit_buffered_record_mesg_broadcaster.hpp
#cpp/fit_buffered_record_mesg_listener.hpp
#cpp/fit_cadence_zone_mesg.hpp
#cpp/fit_cadence_zone_mesg_listener.hpp
#cpp/fit_camera_event_mesg.hpp
#cpp/fit_camera_event_mesg_listener.hpp
#cpp/fit_capabilities_mesg.hpp
#cpp/fit_capabilities_mesg_listener.hpp
#cpp/fit_climb_pro_mesg.hpp
#cpp/fit_climb_pro_mesg_listener.hpp
#cpp/fit_config.hpp
#cpp/fit_connectivity_mesg.hpp
#cpp/fit_connectivity_mesg_listener.hpp
#cpp/fit_course_mesg.hpp
#cpp/fit_course_mesg_listener.hpp
#cpp/fit_course_point_mesg.hpp
#cpp/fit_course_point_mesg_listener.hpp
#cpp/fit_crc.cpp
#cpp/fit_crc.hpp
#cpp/fit_date_time.cpp
#cpp/fit_date_time.hpp
#cpp/fit_decode.cpp
#cpp/fit_decode.hpp
#cpp/fit_developer_data_id_mesg.hpp
#cpp/fit_developer_data_id_mesg_listener.hpp
#cpp/fit_developer_field.cpp
#cpp/fit_developer_field.hpp
#cpp/fit_developer_field_definition.cpp
#cpp/fit_developer_field_definition.hpp
#cpp/fit_developer_field_description.cpp
#cpp/fit_developer_field_description.hpp
#cpp/fit_developer_field_description_listener.hpp
#cpp/fit_device_info_mesg.hpp
#cpp/fit_device_info_mesg_listener.hpp
#cpp/fit_device_settings_mesg.hpp
#cpp/fit_device_settings_mesg_listener.hpp
#cpp/fit_dive_alarm_mesg.hpp
#cpp/fit_dive_alarm_mesg_listener.hpp
#cpp/fit_dive_gas_mesg.hpp
#cpp/fit_dive_gas_mesg_listener.hpp
#cpp/fit_dive_settings_mesg.hpp
#cpp/fit_dive_settings_mesg_listener.hpp
#cpp/fit_dive_summary_mesg.hpp
#cpp/fit_dive_summary_mesg_listener.hpp
#cpp/fit_encode.cpp
#cpp/fit_encode.hpp
#cpp/fit_event_mesg.hpp
#cpp/fit_event_mesg_listener.hpp
#cpp/fit_exd_data_concept_configuration_mesg.hpp
#cpp/fit_exd_data_concept_configuration_mesg_listener.hpp
#cpp/fit_exd_data_field_configuration_mesg.hpp
#cpp/fit_exd_data_field_configuration_mesg_listener.hpp
#cpp/fit_exd_screen_configuration_mesg.hpp
#cpp/fit_exd_screen_configuration_mesg_listener.hpp
#cpp/fit_exercise_title_mesg.hpp
#cpp/fit_exercise_title_mesg_listener.hpp
#cpp/fit_factory.cpp
#cpp/fit_factory.hpp
#cpp/fit_field.cpp
#cpp/fit_field.hpp
#cpp/fit_field_base.cpp
#cpp/fit_field_base.hpp
#cpp/fit_field_capabilities_mesg.hpp
#cpp/fit_field_capabilities_mesg_listener.hpp
#cpp/fit_field_definition.cpp
#cpp/fit_field_definition.hpp
#cpp/fit_field_description_mesg.hpp
#cpp/fit_field_description_mesg_listener.hpp
#cpp/fit_file_capabilities_mesg.hpp
#cpp/fit_file_capabilities_mesg_listener.hpp
#cpp/fit_file_creator_mesg.hpp
#cpp/fit_file_creator_mesg_listener.hpp
#cpp/fit_file_id_mesg.hpp
#cpp/fit_file_id_mesg_listener.hpp
#cpp/fit_goal_mesg.hpp
#cpp/fit_goal_mesg_listener.hpp
#cpp/fit_gps_metadata_mesg.hpp
#cpp/fit_gps_metadata_mesg_listener.hpp
#cpp/fit_gyroscope_data_mesg.hpp
#cpp/fit_gyroscope_data_mesg_listener.hpp
#cpp/fit_hr_mesg.hpp
#cpp/fit_hr_mesg_listener.hpp
#cpp/fit_hr_zone_mesg.hpp
#cpp/fit_hr_zone_mesg_listener.hpp
#cpp/fit_hrm_profile_mesg.hpp
#cpp/fit_hrm_profile_mesg_listener.hpp
#cpp/fit_hrv_mesg.hpp
#cpp/fit_hrv_mesg_listener.hpp
#cpp/fit_jump_mesg.hpp
#cpp/fit_jump_mesg_listener.hpp
#cpp/fit_lap_mesg.hpp
#cpp/fit_lap_mesg_listener.hpp
#cpp/fit_length_mesg.hpp
#cpp/fit_length_mesg_listener.hpp
#cpp/fit_magnetometer_data_mesg.hpp
#cpp/fit_magnetometer_data_mesg_listener.hpp
#cpp/fit_memo_glob_mesg.hpp
#cpp/fit_memo_glob_mesg_listener.hpp
#cpp/fit_mesg.cpp
#cpp/fit_mesg.hpp
#cpp/fit_mesg_broadcast_plugin.hpp
#cpp/fit_mesg_broadcaster.cpp
#cpp/fit_mesg_broadcaster.hpp
#cpp/fit_mesg_capabilities_mesg.hpp
#cpp/fit_mesg_capabilities_mesg_listener.hpp
#cpp/fit_mesg_definition.cpp
#cpp/fit_mesg_definition.hpp
#cpp/fit_mesg_definition_listener.hpp
#cpp/fit_mesg_listener.hpp
#cpp/fit_mesg_with_event.hpp
#cpp/fit_mesg_with_event_broadcaster.cpp
#cpp/fit_mesg_with_event_broadcaster.hpp
#cpp/fit_mesg_with_event_listener.hpp
#cpp/fit_met_zone_mesg.hpp
#cpp/fit_met_zone_mesg_listener.hpp
#cpp/fit_monitoring_info_mesg.hpp
#cpp/fit_monitoring_info_mesg_listener.hpp
#cpp/fit_monitoring_mesg.hpp
#cpp/fit_monitoring_mesg_listener.hpp
#cpp/fit_nmea_sentence_mesg.hpp
#cpp/fit_nmea_sentence_mesg_listener.hpp
#cpp/fit_obdii_data_mesg.hpp
#cpp/fit_obdii_data_mesg_listener.hpp
#cpp/fit_ohr_settings_mesg.hpp
#cpp/fit_ohr_settings_mesg_listener.hpp
#cpp/fit_one_d_sensor_calibration_mesg.hpp
#cpp/fit_one_d_sensor_calibration_mesg_listener.hpp
#cpp/fit_pad_mesg.hpp
#cpp/fit_pad_mesg_listener.hpp
#cpp/fit_power_zone_mesg.hpp
#cpp/fit_power_zone_mesg_listener.hpp
#cpp/fit_profile.cpp
#cpp/fit_profile.hpp
#cpp/fit_protocol_validator.cpp
#cpp/fit_protocol_validator.hpp
#cpp/fit_record_mesg.hpp
#cpp/fit_record_mesg_listener.hpp
#cpp/fit_runtime_exception.hpp
#cpp/fit_schedule_mesg.hpp
#cpp/fit_schedule_mesg_listener.hpp
#cpp/fit_sdm_profile_mesg.hpp
#cpp/fit_sdm_profile_mesg_listener.hpp
#cpp/fit_segment_file_mesg.hpp
#cpp/fit_segment_file_mesg_listener.hpp
#cpp/fit_segment_id_mesg.hpp
#cpp/fit_segment_id_mesg_listener.hpp
#cpp/fit_segment_lap_mesg.hpp
#cpp/fit_segment_lap_mesg_listener.hpp
#cpp/fit_segment_leaderboard_entry_mesg.hpp
#cpp/fit_segment_leaderboard_entry_mesg_listener.hpp
#cpp/fit_segment_point_mesg.hpp
#cpp/fit_segment_point_mesg_listener.hpp
#cpp/fit_session_mesg.hpp
#cpp/fit_session_mesg_listener.hpp
#cpp/fit_set_mesg.hpp
#cpp/fit_set_mesg_listener.hpp
#cpp/fit_slave_device_mesg.hpp
#cpp/fit_slave_device_mesg_listener.hpp
#cpp/fit_software_mesg.hpp
#cpp/fit_software_mesg_listener.hpp
#cpp/fit_speed_zone_mesg.hpp
#cpp/fit_speed_zone_mesg_listener.hpp
#cpp/fit_sport_mesg.hpp
#cpp/fit_sport_mesg_listener.hpp
#cpp/fit_stress_level_mesg.hpp
#cpp/fit_stress_level_mesg_listener.hpp
#cpp/fit_three_d_sensor_calibration_mesg.hpp
#cpp/fit_three_d_sensor_calibration_mesg_listener.hpp
#cpp/fit_timestamp_correlation_mesg.hpp
#cpp/fit_timestamp_correlation_mesg_listener.hpp
#cpp/fit_totals_mesg.hpp
#cpp/fit_totals_mesg_listener.hpp
#cpp/fit_training_file_mesg.hpp
#cpp/fit_training_file_mesg_listener.hpp
#cpp/fit_unicode.cpp
#cpp/fit_unicode.hpp
#cpp/fit_user_profile_mesg.hpp
#cpp/fit_user_profile_mesg_listener.hpp
#cpp/fit_video_clip_mesg.hpp
#cpp/fit_video_clip_mesg_listener.hpp
#cpp/fit_video_description_mesg.hpp
#cpp/fit_video_description_mesg_listener.hpp
#cpp/fit_video_frame_mesg.hpp
#cpp/fit_video_frame_mesg_listener.hpp
#cpp/fit_video_mesg.hpp
#cpp/fit_video_mesg_listener.hpp
#cpp/fit_video_title_mesg.hpp
#cpp/fit_video_title_mesg_listener.hpp
#cpp/fit_watchface_settings_mesg.hpp
#cpp/fit_watchface_settings_mesg_listener.hpp
#cpp/fit_weather_alert_mesg.hpp
#cpp/fit_weather_alert_mesg_listener.hpp
#cpp/fit_weather_conditions_mesg.hpp
#cpp/fit_weather_conditions_mesg_listener.hpp
#cpp/fit_weight_scale_mesg.hpp
#cpp/fit_weight_scale_mesg_listener.hpp
#cpp/fit_workout_mesg.hpp
#cpp/fit_workout_mesg_listener.hpp
#cpp/fit_workout_session_mesg.hpp
#cpp/fit_workout_session_mesg_listener.hpp
#cpp/fit_workout_step_mesg.hpp
#cpp/fit_workout_step_mesg_listener.hpp
#cpp/fit_zones_target_mesg.hpp
#cpp/fit_zones_target_mesg_listener.hpp