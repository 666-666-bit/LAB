`timescale 1ns/1ps
module vga_top (
    input  wire        sys_clk,
    input  wire        sys_rst_n,
    output wire        hsync,
    output wire        vsync,
    output wire [15:0] rgb
);

reg vga_clk;

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        vga_clk <= 1'b0;
    else
        vga_clk <= ~vga_clk;
end

wire [9:0]  pix_x;
wire [9:0]  pix_y;
wire [15:0] pix_data;

vga_ctrl u_vga_ctrl (
    .vga_clk   (vga_clk),
    .sys_rst_n (sys_rst_n),
    .pix_data  (pix_data),
    .pix_x     (pix_x),
    .pix_y     (pix_y),
    .hsync     (hsync),
    .vsync     (vsync),
    .rgb       (rgb)
);

vga_pic u_vga_pic (
    .vga_clk   (vga_clk),
    .sys_rst_n (sys_rst_n),
    .pix_x     (pix_x),
    .pix_y     (pix_y),
    .pix_data  (pix_data)
);

endmodule