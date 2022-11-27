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
        ;% Auto data (a2_local_P)
        ;%
            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% a2_local_P.FXOS87006AxesSensor_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_P.Out1_Y0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_P.Constant_Value
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_local_P.Constant_Value_d
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_local_P.Constant1_Value
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_local_P.Constant_Value_p
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_local_P.Constant1_Value_o
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_local_P.ATR_CMP_DETECTD0_SampleTime
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_local_P.VENT_CMP_DETECTD1_SampleTime
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_local_P.ppm_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_local_P.Accelerationthreshold_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% a2_local_P.mode_Value
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% a2_local_P.Switch_Threshold
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% a2_local_P.maximumsensordrivenrate_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% a2_local_P.reactiontime_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% a2_local_P.recoverytime1_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% a2_local_P.Memory_InitialCondition
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% a2_local_P.ARPmsec_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% a2_local_P.AtrialPluseWidthmsec_Value
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% a2_local_P.VRPmsec_Value
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% a2_local_P.VentricularPluseWidthmsec_Value
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% a2_local_P.AtrialAmplitudevolt_Value
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% a2_local_P.Constant_Value_b
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% a2_local_P.Gain_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% a2_local_P.VentricularAmplitude_Value
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% a2_local_P.Constant1_Value_d
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% a2_local_P.Gain1_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% a2_local_P.umin60sec60000msec2_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% a2_local_P.umin60sec60000msec2_Value_i
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% a2_local_P.Switch_Threshold_l
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% a2_local_P.Atrialthresholdvolt_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% a2_local_P.Voltage_Value
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% a2_local_P.Gain_Gain_n
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% a2_local_P.Ventriclethresholdvolt_Value
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% a2_local_P.Gain1_Gain_p
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

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
        nTotSects     = 2;
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
        ;% Auto data (a2_local_B)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% a2_local_B.mode
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_B.ARPmsec
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_B.AtrialPluseWidthmsec
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_local_B.VRPmsec
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_local_B.VentricularPluseWidthmsec
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_local_B.Gain
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_local_B.Gain1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_local_B.Divide2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_local_B.Divide2_m
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_local_B.time_response
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_local_B.PACING_REF_PWM
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% a2_local_B.Add
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% a2_local_B.FXOS87006AxesSensor
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% a2_local_B.RelationalOperator
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_B.VENT_CMP_DETECTD1
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_B.ATR_CMP_DETECTD0
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_local_B.Z_VENT_CTRL
                    section.data(4).logicalSrcIdx = 16;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_local_B.VENT_PACE_CTRL
                    section.data(5).logicalSrcIdx = 17;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_local_B.PACE_GND_CTRL
                    section.data(6).logicalSrcIdx = 18;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_local_B.ATR_PACE_CTRL
                    section.data(7).logicalSrcIdx = 19;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_local_B.VENT_GND_CTRL
                    section.data(8).logicalSrcIdx = 20;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_local_B.Z_ATR_CTRL
                    section.data(9).logicalSrcIdx = 21;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_local_B.PACE_CHARGE_CTRL
                    section.data(10).logicalSrcIdx = 22;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_local_B.ATR_GND_CTRL
                    section.data(11).logicalSrcIdx = 23;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
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
        sectIdxOffset = 2;

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
        ;% Auto data (a2_local_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_local_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% a2_local_DW.obj_i
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_DW.obj_f
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% a2_local_DW.obj_m
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_DW.obj_mn
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_DW.obj_k
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_local_DW.obj_e
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_local_DW.obj_d
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_local_DW.obj_h
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_local_DW.obj_a
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_local_DW.obj_p
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_local_DW.obj_o
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_local_DW.obj_ay
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% a2_local_DW.obj_kr
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% a2_local_DW.obj_ki
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_DW.obj_p4
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_DW.obj_g
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_local_DW.Memory_PreviousInput
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% a2_local_DW.sensorresponserate_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_DW.LRI_TR_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_DW.LRI_TR1_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_local_DW.acc_detect01_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_local_DW.accel_active_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_local_DW.acc_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_local_DW.Scope_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 24;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% a2_local_DW.is_c3_a2_local
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

                    ;% a2_local_DW.is_VOOR
                    section.data(2).logicalSrcIdx = 27;
                    section.data(2).dtTransOffset = 1;

                    ;% a2_local_DW.is_AOOR
                    section.data(3).logicalSrcIdx = 28;
                    section.data(3).dtTransOffset = 2;

                    ;% a2_local_DW.is_VVIR
                    section.data(4).logicalSrcIdx = 29;
                    section.data(4).dtTransOffset = 3;

                    ;% a2_local_DW.is_AAIR
                    section.data(5).logicalSrcIdx = 30;
                    section.data(5).dtTransOffset = 4;

                    ;% a2_local_DW.is_VOO
                    section.data(6).logicalSrcIdx = 31;
                    section.data(6).dtTransOffset = 5;

                    ;% a2_local_DW.is_AOO
                    section.data(7).logicalSrcIdx = 32;
                    section.data(7).dtTransOffset = 6;

                    ;% a2_local_DW.is_VVI
                    section.data(8).logicalSrcIdx = 33;
                    section.data(8).dtTransOffset = 7;

                    ;% a2_local_DW.is_AAI
                    section.data(9).logicalSrcIdx = 34;
                    section.data(9).dtTransOffset = 8;

                    ;% a2_local_DW.temporalCounter_i1
                    section.data(10).logicalSrcIdx = 35;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_local_DW.calculateacceleration3D_SubsysR
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% a2_local_DW.is_active_c3_a2_local
                    section.data(1).logicalSrcIdx = 37;
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


    targMap.checksum0 = 1536935259;
    targMap.checksum1 = 811435545;
    targMap.checksum2 = 1227525428;
    targMap.checksum3 = 1513025184;

