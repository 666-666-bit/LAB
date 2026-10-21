`timescale 1ns / 1ps

module counter_tb;

    reg        sys_clk;
    reg        sys_rst_n;
    wire       led_out;

    
    localparam SIM_CNT_MAX = 25'd5;

   
    counter #(
        .CNT_MAX(SIM_CNT_MAX)
    ) u_counter (
        .sys_clk   (sys_clk),
        .sys_rst_n (sys_rst_n),
        .led_out   (led_out)
    );

   
    initial begin
        sys_clk = 1'b0;
        forever #10 sys_clk = ~sys_clk;
    end

    initial begin
       
        $dumpfile("sim-wave/counter.vcd");
        $dumpvars(0, counter_tb);

       
        sys_rst_n = 1'b0;
        #40;

      
        sys_rst_n = 1'b1;

        
        #300;

       
        #15; // 避开时钟沿，体现异步特性
        sys_rst_n = 1'b0;
        #30;
        
        
        sys_rst_n = 1'b1;
        #200;

        $display("Simulation finished successfully.");
        $finish;
    end

endmodule