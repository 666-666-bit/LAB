module running_light #(
    parameter MAX_CNT = 25_000_000
)(
    input  wire        sys_clk,
    input  wire        sys_rst_n,
    output reg  [3:0]  led_out
);

    reg [24:0] cnt;

    always @(posedge sys_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            cnt <= 25'd0;
        end else if (cnt == MAX_CNT - 1) begin
            cnt <= 25'd0;
        end else begin
            cnt <= cnt + 1'b1;
        end
    end

    always @(posedge sys_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            led_out <= 4'b1110;
        end else if (cnt == MAX_CNT - 1) begin
            led_out <= {led_out[2:0], led_out[3]};
        end
    end

endmodule