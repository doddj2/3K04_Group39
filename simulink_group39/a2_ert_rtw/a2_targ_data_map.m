    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (a2_P)
        ;%
            section.nData     = 30;
            section.data(30)  = dumData; %prealloc

                    ;% a2_P.FXOS87006AxesSensor_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_P.Constant_Value
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_P.Constant1_Value
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_P.ATR_CMP_DETECTD0_SampleTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_P.VENT_CMP_DETECTD1_SampleTime
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_P.Constant_Value_h
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_P.Accelerationthreshold_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_P.ppm_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_P.maximumsensordrivenrate_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_P.reactiontime_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_P.recoverytime1_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% a2_P.Memory_InitialCondition
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% a2_P.umin60sec60000msec2_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% a2_P.ARPmsec_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% a2_P.AtrialPluseWidthmsec_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% a2_P.mode_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% a2_P.VRPmsec_Value
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% a2_P.VentricularPluseWidthmsec_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% a2_P.AtrialAmplitudevolt_Value
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% a2_P.Constant_Value_b
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% a2_P.Gain_Gain
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% a2_P.VentricularAmplitude_Value
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% a2_P.Constant1_Value_d
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% a2_P.Gain1_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% a2_P.Switch_Threshold
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% a2_P.Atrialthresholdvolt_Value
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% a2_P.Voltage_Value
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% a2_P.Gain_Gain_n
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% a2_P.Ventriclethresholdvolt_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% a2_P.Gain1_Gain_p
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (a2_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_B.FXOS87006AxesSensor
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% a2_B.Divide2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_B.ARPmsec
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_B.AtrialPluseWidthmsec
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_B.mode
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_B.VRPmsec
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_B.VentricularPluseWidthmsec
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_B.Gain
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_B.Gain1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_B.time_response
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_B.PACING_REF_PWM
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_B.MovingAverage
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% a2_B.RelationalOperator
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_B.VENT_CMP_DETECTD1
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_B.ATR_CMP_DETECTD0
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_B.Z_VENT_CTRL
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_B.VENT_PACE_CTRL
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_B.PACE_GND_CTRL
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_B.ATR_PACE_CTRL
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_B.VENT_GND_CTRL
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_B.Z_ATR_CTRL
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_B.PACE_CHARGE_CTRL
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_B.ATR_GND_CTRL
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 9;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (a2_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_DW.obj_g
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% a2_DW.obj_i
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_DW.obj_f
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% a2_DW.obj_m
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_DW.obj_mn
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_DW.obj_k
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_DW.obj_e
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_DW.obj_d
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_DW.obj_h
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_DW.obj_a
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_DW.obj_p
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_DW.obj_o
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_DW.obj_ay
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_DW.obj_kr
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% a2_DW.obj_ki
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_DW.obj_p4
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_DW.obj_gc
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_DW.Memory_PreviousInput
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% a2_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_DW.acc_detect01_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_DW.accel_active_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_DW.sensorresponserate_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_DW.acc_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% a2_DW.is_c3_a2
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_DW.is_VOO
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_DW.is_AOO
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_DW.is_VVI
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_DW.is_AAI
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_DW.temporalCounter_i1
                    section.data(6).logicalSrcIdx = 30;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_DW.is_active_c3_a2
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3478564906;
    targMap.checksum1 = 2737413696;
    targMap.checksum2 = 3748823978;
    targMap.checksum3 = 1037838211;

