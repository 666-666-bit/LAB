`timescale 1ns/1ps
module screen_fsm (
    input  wire sys_clk,
    input  wire sys_rst_n,
    input  wire key_flag,
    output reg [1:0] cur_state
);

localparam S_BARS = 2'b00;
localparam S_MUST = 2'b01;
localparam S_END  = 2'b10;

reg [1:0] next_state;

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        cur_state <= S_BARS;
    else
        cur_state <= next_state;
end

always @(*) begin
    case (cur_state)
        S_BARS:  next_state = key_flag ? S_MUST : S_BARS;
        S_MUST:  next_state = key_flag ? S_END  : S_MUST;
        S_END:   next_state = key_flag ? S_BARS : S_END;
        default: next_state = S_BARS;
    endcase
end

endmodule