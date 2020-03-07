
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

library work;

entity nios2_custom_pio is
	generic(
		-- Default frequency used in synthesis.
		constant CLK_FREQ : positive := 12000000
	);
	port(
		-- On MAX1000.
		-- System signals.
		i_clk                      :  in std_logic; -- 12MHz clock.
		in_rst                     :  in std_logic;
		
		
		-- LEDs.
		o_led                      : out std_logic_vector(7 downto 0);
		
		
		
		-- On LPRS1_MAX1000_Shield.
		-- Inputs.
		i_sw                       :  in std_logic_vector(7 downto 0)
	);
end entity;

architecture nios2_custom_pio_arch of nios2_custom_pio is
	
	signal rst : std_logic;
	
	component nios2_custom_pio_qsys is
		port (
			clk_clk   : in  std_logic                    := 'X';             -- clk
			pio_pi    : in  std_logic_vector(7 downto 0) := (others => 'X'); -- pi
			pio_po    : out std_logic_vector(7 downto 0);                    -- po
			rst_reset : in  std_logic                    := 'X'              -- reset
		);
	end component nios2_custom_pio_qsys;
	
begin
	
	rst <= not in_rst;
	
	u0 : component nios2_custom_pio_qsys
	port map (
		clk_clk    => i_clk,
		rst_reset  => rst,
		pio_pi     => i_sw,
		pio_po     => o_led
	);

end architecture;
