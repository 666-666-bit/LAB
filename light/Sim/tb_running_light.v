`timescale 1ns/1ns

module tb_running_light();

    reg        sys_clk;
    reg        sys_rst_n;
    wire [3:0] led_out;

 
    running_light #(
        .MAX_CNT(10)
    ) u_running_light (
        .sys_clk   (sys_clk),
        .sys_rst_n (sys_rst_n),
        .led_out   (led_out)
    );

    always #10 sys_clk = ~sys_clk;

    initial begin

        $dumpfile("running_light.vcd");
        $dumpvars(0, tb_running_light);

    
        sys_clk   = 0;
        sys_rst_n = 0; 
        
        #35;
        sys_rst_n = 1; 
        

#1000;

      
        sys_rst_n = 0; 
        #25;
        sys_rst_n = 1;

        #500;
        $finish; 
    end

endmodule
