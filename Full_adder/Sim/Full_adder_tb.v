`timescale 1ns / 1ns

module Full_adder_tb;
    reg  key_a;
    reg  key_b;
    reg  key_cin;
    wire led_s;
    wire led_cout;

    Full_adder dut (
        .key_a   (key_a),
        .key_b   (key_b),
        .key_cin (key_cin),
        .led_s   (led_s),
        .led_cout(led_cout)
    );

    initial begin
        $dumpfile("Full_adder_tb.vcd");
        $dumpvars(0, Full_adder_tb);

        // Case 0: A=0, B=0, Cin=0
        key_a = 1; key_b = 1; key_cin = 1; #20;
        // Case 1: A=0, B=0, Cin=1
        key_a = 1; key_b = 1; key_cin = 0; #20;
        // Case 2: A=0, B=1, Cin=0
        key_a = 1; key_b = 0; key_cin = 1; #20;
        // Case 3: A=0, B=1, Cin=1
        key_a = 1; key_b = 0; key_cin = 0; #20;
        // Case 4: A=1, B=0, Cin=0
        key_a = 0; key_b = 1; key_cin = 1; #20;
        // Case 5: A=1, B=0, Cin=1
        key_a = 0; key_b = 1; key_cin = 0; #20;
        // Case 6: A=1, B=1, Cin=0
        key_a = 0; key_b = 0; key_cin = 1; #20;
        // Case 7: A=1, B=1, Cin=1
        key_a = 0; key_b = 0; key_cin = 0; #20;

        $finish;
    end
endmodule