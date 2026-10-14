`timescale 1ns / 1ns
module comparator_1bit_tb;
    reg key_a = 1;
    reg key_b = 1;
    wire led_less;
    wire led_equal;
    wire led_greater;

 
    comparator_1bit dut (
        .key_a(key_a),
        .key_b(key_b),
        .led_less(led_less),
        .led_equal(led_equal),
        .led_greater(led_greater)
    );

    initial begin
        $dumpfile("comparator_tb.vcd"); 
        $dumpvars(0, comparator_1bit_tb);

        #20 key_a = 1; key_b = 1; 
        #20 key_a = 0; key_b = 1;
        #20 key_a = 1; key_b = 0;
        #20 key_a = 0; key_b = 0;
        
        #20 $finish;
    end
endmodule
