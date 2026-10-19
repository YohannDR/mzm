	.align 2
	@********************** Voicegroup **********************@

	.global voicegroup006
voicegroup006:	@ 0x0808DF24
	voice_directsound Cn3, 0, DirectSoundData_081040C8, 255, 0, 255, 0	@0808DF24
	voice_directsound Cn3, 0, DirectSoundData_080CD3AC, 255, 0, 255, 0	@0808DF30
	voice_noise 60, 0, 0, 0, 0, 0, 15, 0	@0808DF3C
	voice_noise 60, 0, 0, 1, 0, 0, 15, 0	@0808DF48
	voice_directsound Cn3, 0, DirectSoundData_080CE470, 255, 0, 255, 0	@0808DF54
	voice_directsound_reverse Cn3, 0, DirectSoundData_080CE470, 255, 0, 255, 0	@0808DF60
	voice_directsound Cn3, 0, DirectSoundData_08104EDC, 255, 0, 255, 0	@0808DF6C
	voice_noise 60, 0, 0, 1, 0, 0, 15, 3	@0808DF78
	voice_directsound Cn3, 0, DirectSoundData_08100CBC, 255, 0, 255, 0	@0808DF84
	voice_directsound Cn3, 0, DirectSoundData_080CDF24, 255, 0, 255, 0	@0808DF90
	voice_directsound Cn3, 0, DirectSoundData_080FEFFC, 255, 0, 255, 0	@0808DF9C
	voice_noise 60, 0, 0, 0, 0, 0, 10, 4	@0808DFA8
	voice_directsound Cn3, 0, DirectSoundData_0809F8A4, 255, 0, 255, 0	@0808DFB4
