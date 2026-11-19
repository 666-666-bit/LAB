`timescale 1ns/1ps
module key_debounce (
    input  wire sys_clk,
    input  wire sys_rst_n,
    input  wire key_in,
    output reg  key_flag
);

parameter CNT_MAX = 19'd10;

reg key_reg;
reg [18:0] cnt_20ms;

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        key_reg <= 1'b1;
        cnt_20ms <= 19'd0;
    end else begin
        key_reg <= key_in;
        if (key_reg != key_in)
            cnt_20ms <= CNT_MAX;
        else if (cnt_20ms > 19'd0)
            cnt_20ms <= cnt_20ms - 1'b1;
    end
end

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        key_flag <= 1'b0;
    else if (cnt_20ms == 19'd1 && key_in == 1'b0)
        key_flag <= 1'b1;
    else
        key_flag <= 1'b0;
end

endmodule
