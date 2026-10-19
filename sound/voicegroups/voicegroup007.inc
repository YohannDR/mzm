	.align 2
	@********************** Voicegroup **********************@

	.global voicegroup007
voicegroup007:	@ 0x0808DFC0
	voice_directsound Cn3, 0, DirectSoundData_081059B4, 255, 0, 255, 0	@0808DFC0
	voice_directsound Cn3, 0, DirectSoundData_08107498, 255, 0, 255, 0	@0808DFCC
	voice_noise 60, 0, 0, 0, 0, 0, 15, 0	@0808DFD8
	voice_directsound Cn3, 0, DirectSoundData_080CD3AC, 255, 0, 255, 0	@0808DFE4
	voice_directsound Cn3, 0, DirectSoundData_08100CBC, 255, 0, 255, 0	@0808DFF0
	voice_directsound Cn3, 0, DirectSoundData_080E2644, 255, 0, 255, 0	@0808DFFC
	voice_noise 60, 0, 0, 0, 0, 0, 10, 4	@0808E008
	voice_directsound Cn3, 0, DirectSoundData_080CF368, 255, 0, 255, 0	@0808E014
	voice_directsound Cn3, 0, DirectSoundData_080E4A7C, 255, 0, 255, 0	@0808E020
	voice_directsound Cn3, 0, DirectSoundData_080DAADC, 255, 0, 255, 0	@0808E02C
