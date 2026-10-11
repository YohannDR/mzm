	.align 2
	@********************** Voicegroup **********************@

	.global voicegroup021
voicegroup021:	@ 0x0808F004
	voice_square_1 0, 2, 0, 0, 15, 0	@0808F004
	voice_square_1 0, 2, 0, 0, 15, 0	@0808F010
	voice_square_1 0, 2, 0, 0, 15, 0	@0808F01C
	voice_directsound Cn3, 0, DirectSoundData_0816463C, 51, 0, 255, 127	@0808F028
	voice_square_1 0, 2, 0, 0, 15, 0	@0808F034
	voice_directsound Cn3, 0, DirectSoundData_08177EFC, 255, 127, 255, 165	@0808F040
	voice_square_1 0, 2, 0, 0, 15, 0	@0808F04C
	voice_square_1 0, 2, 0, 0, 15, 0	@0808F058
	voice_directsound Cn3, 0, DirectSoundData_08179FF0, 255, 0, 255, 0	@0808F064
