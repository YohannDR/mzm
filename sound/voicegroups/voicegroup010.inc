	.align 2
	@********************** Voicegroup **********************@

	.global voicegroup010
voicegroup010:	@ 0x0808E164
	voice_directsound Cn3, 0, DirectSoundData_080EA0FC, 255, 0, 255, 0	@0808E164
	voice_directsound Cn3, 0, DirectSoundData_080DA120, 128, 89, 206, 0	@0808E170
	voice_noise 60, 0, 0, 0, 0, 0, 15, 5	@0808E17C
	voice_directsound Cn3, 0, DirectSoundData_080CD3AC, 255, 0, 255, 0	@0808E188
	voice_directsound Cn3, 0, DirectSoundData_080DA120, 255, 89, 206, 0	@0808E194
	voice_noise 60, 0, 0, 0, 0, 0, 14, 5	@0808E1A0
	voice_directsound Cn3, 0, DirectSoundData_080CDF24, 255, 0, 255, 0	@0808E1AC
	voice_directsound Cn3, 0, DirectSoundData_080E2644, 255, 0, 255, 0	@0808E1B8
	voice_directsound Cn3, 0, DirectSoundData_080FEFFC, 255, 0, 255, 0	@0808E1C4
	voice_directsound Cn3, 0, DirectSoundData_080D9600, 255, 0, 255, 0	@0808E1D0
	voice_directsound Cn3, 0, DirectSoundData_080D9ADC, 255, 0, 255, 0	@0808E1DC
	voice_directsound Cn3, 0, DirectSoundData_0810C7C8, 255, 0, 255, 0	@0808E1E8
	voice_directsound Cn3, 0, DirectSoundData_080DAADC, 255, 0, 255, 0	@0808E1F4
	voice_directsound Cn3, 0, DirectSoundData_080A78F4, 255, 0, 255, 0	@0808E200
	voice_noise 60, 0, 0, 0, 0, 0, 15, 4	@0808E20C
	voice_directsound Cn3, 0, DirectSoundData_0810CD2C, 255, 0, 255, 0	@0808E218
	voice_directsound_reverse Cn3, 0, DirectSoundData_0810CD2C, 255, 0, 255, 0	@0808E224
	voice_noise 60, 0, 0, 1, 0, 0, 15, 4	@0808E230
	voice_noise 60, 0, 0, 0, 0, 0, 10, 4	@0808E23C
	voice_directsound Cn3, 0, DirectSoundData_08100CBC, 255, 0, 255, 0	@0808E248
	voice_directsound Cn3, 0, DirectSoundData_08101B40, 255, 0, 255, 0	@0808E254
	voice_noise 60, 0, 0, 0, 0, 0, 13, 5	@0808E260
