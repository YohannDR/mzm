	.align 2
	@********************** Voicegroup **********************@

	.global voicegroup011
voicegroup011:	@ 0x0808E26C
	voice_directsound Cn3, 0, DirectSoundData_08110580, 255, 0, 255, 0	@0808E26C
	voice_directsound_reverse Cn3, 0, DirectSoundData_080DF8D8, 255, 0, 255, 0	@0808E278
	voice_directsound Cn3, 0, DirectSoundData_080CF368, 255, 0, 255, 0	@0808E284
	voice_square_1 0, 2, 0, 0, 15, 0	@0808E290
	voice_square_1 0, 2, 0, 0, 15, 0	@0808E29C
	voice_noise 60, 0, 0, 0, 0, 0, 14, 5	@0808E2A8
	voice_directsound Cn3, 0, DirectSoundData_080CDF24, 255, 0, 255, 0	@0808E2B4
	voice_directsound Cn3, 0, DirectSoundData_080E2644, 255, 0, 255, 0	@0808E2C0
	voice_directsound Cn3, 0, DirectSoundData_080FEFFC, 255, 0, 255, 0	@0808E2CC
	voice_directsound Cn3, 0, DirectSoundData_080A331C, 255, 0, 255, 0	@0808E2D8
	voice_directsound Cn3, 0, DirectSoundData_08110C94, 255, 0, 255, 0	@0808E2E4
	voice_directsound Cn3, 0, DirectSoundData_08100CBC, 255, 0, 255, 0	@0808E2F0
	voice_directsound Cn3, 0, DirectSoundData_080E2644, 255, 0, 255, 0	@0808E2FC
	voice_noise 60, 0, 0, 0, 0, 0, 10, 4	@0808E308
	voice_noise 60, 0, 0, 1, 0, 0, 15, 4	@0808E314
