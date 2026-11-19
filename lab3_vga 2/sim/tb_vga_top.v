`timescale 1ns/1ps

module tb_vga_top;

reg sys_clk;
reg sys_rst_n;
wire hsync;
wire vsync;
wire [15:0] rgb;

vga_top u_vga_top (
    .sys_clk   (sys_clk),
    .sys_rst_n (sys_rst_n),
    .hsync     (hsync),
    .vsync     (vsync),
    .rgb       (rgb)
);

always #10 sys_clk = ~sys_clk;

initial begin
    sys_clk   = 1'b0;
    sys_rst_n = 1'b0;

    $dumpfile("sim/vga_top.vcd");
    $dumpvars(0, tb_vga_top);

    #100;
    sys_rst_n = 1'b1;

    #35000;
    $finish;
end

endmodule