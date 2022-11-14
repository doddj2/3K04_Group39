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
        ;% Auto data (assignment_1_P)
        ;%
            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% assignment_1_P.Constant_Value
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_P.Constant1_Value
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% assignment_1_P.FXOS87006AxesSensor_SampleTime
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% assignment_1_P.ATR_CMP_DETECTD0_SampleTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% assignment_1_P.VENT_CMP_DETECTD1_SampleTime
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% assignment_1_P.ppm_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% assignment_1_P.umin60sec60000msec2_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% assignment_1_P.ARPmsec_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% assignment_1_P.AtrialPluseWidthmsec_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% assignment_1_P.mode_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% assignment_1_P.VRPmsec_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% assignment_1_P.VentricularPluseWidthmsec_Value
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% assignment_1_P.AtrialAmplitudevolt_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% assignment_1_P.Constant_Value_b
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% assignment_1_P.Gain_Gain
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% assignment_1_P.VentricularAmplitude_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% assignment_1_P.Constant1_Value_d
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% assignment_1_P.Gain1_Gain
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% assignment_1_P.Switch_Threshold
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% assignment_1_P.Atrialthresholdvolt_Value
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% assignment_1_P.Voltage_Value
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% assignment_1_P.Gain_Gain_n
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% assignment_1_P.Ventriclethresholdvolt_Value
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% assignment_1_P.Gain1_Gain_p
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

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
        ;% Auto data (assignment_1_B)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% assignment_1_B.Divide2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_B.ARPmsec
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% assignment_1_B.AtrialPluseWidthmsec
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% assignment_1_B.mode
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% assignment_1_B.VRPmsec
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% assignment_1_B.VentricularPluseWidthmsec
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% assignment_1_B.Gain
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% assignment_1_B.Gain1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% assignment_1_B.PACING_REF_PWM
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% assignment_1_B.MovingAverage
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% assignment_1_B.VENT_CMP_DETECTD1
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_B.ATR_CMP_DETECTD0
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% assignment_1_B.Z_VENT_CTRL
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% assignment_1_B.VENT_PACE_CTRL
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% assignment_1_B.PACE_GND_CTRL
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 4;

                    ;% assignment_1_B.ATR_PACE_CTRL
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 5;

                    ;% assignment_1_B.VENT_GND_CTRL
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 6;

                    ;% assignment_1_B.Z_ATR_CTRL
                    section.data(8).logicalSrcIdx = 17;
                    section.data(8).dtTransOffset = 7;

                    ;% assignment_1_B.PACE_CHARGE_CTRL
                    section.data(9).logicalSrcIdx = 18;
                    section.data(9).dtTransOffset = 8;

                    ;% assignment_1_B.ATR_GND_CTRL
                    section.data(10).logicalSrcIdx = 19;
                    section.data(10).dtTransOffset = 9;

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
        nTotSects     = 8;
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
        ;% Auto data (assignment_1_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% assignment_1_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% assignment_1_DW.obj_f
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% assignment_1_DW.obj_i
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_DW.obj_f0
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% assignment_1_DW.obj_k
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_DW.obj_p
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% assignment_1_DW.obj_g
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% assignment_1_DW.obj_d
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_DW.obj_i4
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% assignment_1_DW.obj_m
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% assignment_1_DW.obj_mn
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 3;

                    ;% assignment_1_DW.obj_ko
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 4;

                    ;% assignment_1_DW.obj_e
                    section.data(6).logicalSrcIdx = 12;
                    section.data(6).dtTransOffset = 5;

                    ;% assignment_1_DW.obj_df
                    section.data(7).logicalSrcIdx = 13;
                    section.data(7).dtTransOffset = 6;

                    ;% assignment_1_DW.obj_h
                    section.data(8).logicalSrcIdx = 14;
                    section.data(8).dtTransOffset = 7;

                    ;% assignment_1_DW.obj_a
                    section.data(9).logicalSrcIdx = 15;
                    section.data(9).dtTransOffset = 8;

                    ;% assignment_1_DW.obj_pu
                    section.data(10).logicalSrcIdx = 16;
                    section.data(10).dtTransOffset = 9;

                    ;% assignment_1_DW.obj_o
                    section.data(11).logicalSrcIdx = 17;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% assignment_1_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% assignment_1_DW.is_c3_assignment_1
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% assignment_1_DW.is_VOO
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% assignment_1_DW.is_AOO
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 2;

                    ;% assignment_1_DW.is_VVI
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 3;

                    ;% assignment_1_DW.is_AAI
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 4;

                    ;% assignment_1_DW.temporalCounter_i1
                    section.data(6).logicalSrcIdx = 25;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% assignment_1_DW.is_active_c3_assignment_1
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
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


    targMap.checksum0 = 112361251;
    targMap.checksum1 = 3456612692;
    targMap.checksum2 = 2888552710;
    targMap.checksum3 = 666746467;

