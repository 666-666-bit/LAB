`timescale 1ns / 1ns

module comparator (
    input wire key_a,
    input wire key_b,
    output wire led_less,
    output wire led_equal,
    output wire led_greater);
   
   
    wire logic_a = ~key_a;
    wire logic_b = ~key_b;

    assign led_less    = ~(logic_a < logic_b);
    assign led_equal   = ~(logic_a == logic_b);
    assign led_greater = ~(logic_a > logic_b);
endmodule
