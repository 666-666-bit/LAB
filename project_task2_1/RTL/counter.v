`timescale 1ns / 1ps

module counter (
    input  wire sys_clk,
    input  wire sys_rst_n,
    output reg  led_out
);

    parameter CNT_MAX = 25'd24_999_999;

    reg [24:0] cnt;

    always @(posedge sys_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            cnt     <= 25'd0;
            led_out <= 1'b0;
        end else if (cnt == CNT_MAX) begin
            cnt     <= 25'd0;
            led_out <= ~led_out;
        end else begin
            cnt     <= cnt + 1'b1;
            led_out <= led_out;
        end
    end

endmodule