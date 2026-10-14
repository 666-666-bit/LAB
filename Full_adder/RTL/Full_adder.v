`timescale 1ns / 1ns

module Full_adder (
    input  wire key_a,    
    input  wire key_b,    
    input  wire key_cin, 
    output wire led_s,  
    output wire led_cout 
);

    wire a   = ~key_a;
    wire b   = ~key_b;
    wire cin = ~key_cin;


    wire s; 
    wire cout;
    assign {cout, s} = a+b+cin;

    assign led_s    = ~s;
    assign led_cout = ~cout;

endmodule