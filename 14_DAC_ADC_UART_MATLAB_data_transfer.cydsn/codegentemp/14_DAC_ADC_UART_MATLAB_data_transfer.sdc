# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\h_da\Lecturs\Basic Embedded\Embedded_basics\14_DAC_ADC_UART_MATLAB_data_transfer.cydsn\14_DAC_ADC_UART_MATLAB_data_transfer.cyprj
# Date: Wed, 10 Jun 2020 00:14:36 GMT
#set_units -time ns
create_clock -name {ADC_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {WaveDAC_DacClk(routed)} -period 100000 -waveform {0 50000} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {ADC_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {UART_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 39 77} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {WaveDAC_DacClk} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2401 4801} [list [get_pins {ClockBlock/dclk_glb_2}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for D:\h_da\Lecturs\Basic Embedded\Embedded_basics\14_DAC_ADC_UART_MATLAB_data_transfer.cydsn\TopDesign\TopDesign.cysch
# Project: D:\h_da\Lecturs\Basic Embedded\Embedded_basics\14_DAC_ADC_UART_MATLAB_data_transfer.cydsn\14_DAC_ADC_UART_MATLAB_data_transfer.cyprj
# Date: Wed, 10 Jun 2020 00:14:32 GMT
