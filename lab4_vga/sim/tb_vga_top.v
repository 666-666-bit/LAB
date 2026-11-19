`timescale 1ns/1ps
module tb_vga_top;

reg sys_clk;
reg sys_rst_n;
reg key_in;
wire hsync;
wire vsync;
wire [15:0] rgb;


vga_top #(.DEBOUNCE_CNT(19'd20)) dut (
    .sys_clk   (sys_clk),
    .sys_rst_n (sys_rst_n),
    .key_in    (key_in),
    .hsync     (hsync),
    .vsync     (vsync),
    .rgb       (rgb)
);

always #10 sys_clk = ~sys_clk;


task press_key_with_bounce;
begin

    key_in = 0; #40; key_in = 1; #60; key_in = 0; #40; key_in = 1; #20;
  
    key_in = 0; #1000;

    key_in = 1; #40; key_in = 0; #40; key_in = 1; #60;
  
    key_in = 1; #1000;
end
endtask

initial begin
    sys_clk   = 1'b0;
    sys_rst_n = 1'b0;
    key_in    = 1'b1;

    $dumpfile("vga_top.vcd");
    $dumpvars(0, tb_vga_top);

    #100;
    sys_rst_n = 1'b1;
    #200;

    press_key_with_bounce();

    press_key_with_bounce();

    press_key_with_bounce();

   
    #500;
    key_in = 0; #500;
    sys_rst_n = 0; #200;
    sys_rst_n = 1; #500;

    #2000;
    $finish;
end

endmodule