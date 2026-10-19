	.align 2
	@********************** Voicegroup **********************@

	.global voicegroup012
voicegroup012:	@ 0x0808E320
	voice_directsound Cn3, 0, DirectSoundData_080E1CDC, 255, 0, 255, 0	@0808E320
	voice_directsound Cn3, 0, DirectSoundData_08112B3C, 255, 0, 255, 0	@0808E32C
	voice_directsound Cn3, 0, DirectSoundData_080EB0D0, 255, 0, 255, 0	@0808E338
	voice_directsound Cn3, 0, DirectSoundData_080E04C8, 255, 0, 255, 0	@0808E344
	voice_directsound Cn3, 0, DirectSoundData_080EC318, 255, 0, 255, 0	@0808E350
	voice_directsound Cn3, 0, DirectSoundData_080DC898, 51, 0, 255, 0	@0808E35C
	voice_directsound Cn3, 0, DirectSoundData_080DC898, 255, 0, 255, 0	@0808E368
	voice_directsound Cn3, 0, DirectSoundData_0811333C, 64, 0, 255, 0	@0808E374
	voice_noise 60, 0, 0, 0, 0, 0, 15, 4	@0808E380
	voice_directsound Cn3, 0, DirectSoundData_080A331C, 255, 0, 255, 0	@0808E38C
	voice_directsound Cn3, 0, DirectSoundData_080DA120, 128, 89, 206, 0	@0808E398
