# Blender opdracht voor visuals opdracht CSD2D

> LET OP! Ik heb de opdracht net anders geïnterpreteerd, met toestemming. Mijn eindresultaat is dus niet realtime.

> Als je geen blender hebt: ik heb de scripts en node setups ook los in de git gezet, zodat je ze wel kan bekijken.

Voor de (Realtime) Visuals bij Muziek opdracht heb ik besloten om Blender te gebuiken vanwege de vele rendermogelijkheden, met als doel om te kijken of Blender geschikt is voor het maken van audio reactieve visuals.

Om een beeld te krijgen van de mogelijkheden in Blender heb ik een kort onderzoekje gedaan, zie [het document](BlenderMogelijkhedenOnderzoekje.pdf).

## Het plan

Ik heb al eerder gekeken naar realtime visuals in p5, three.js en game-engines zoals Unity en ik wou deze keer wat anders doen dus ik ga dit project gebruiken om offline visuals genereren met de Blender API en Shader Nodes. 

**Ik ga hierbij vooral gebruik maken van features die niet mogelijk zijn in realtime zoals path-tracing en volumetric lighting.**

* De vormen ga ik genereren met Volumetric Shader Nodes in Blender, dit creëert een ruimte binnen een object waarin je met textures vormen kan genereren.

* Ik ga een (kort) stukje muziek/geluid maken met veel dynamisch verschil om het effect duidelijk te laten zien.

* Met behulp van de Python Blender API ga ik parameters zoals lichtintensiteit en beweging van de vormen aansturen op basis van de hardheid van het geluid

* Ik wil met al deze dingen gaan expirimenteren en een aantal renders maken als een proof of concept

## MVP

Het eindresultaat moet minstens bevatten:
* Coole vormen gemaakt met Shader Nodes (minstens 2 korte filmpjes)
* Een Python script dat een audio bestand inlaad, de hardheid berekend en dit naar parameter keyframes schrijft.
* Documentatie over mijn bevingingen en conclusies


## Het proces: Mijn strijd met Blender

Voor mijn 2 proof of concept filmpjes wilde ik de intensiteit van het geluid koppelen aan de lichtintensiteit en aan de beweging van de vormen.

Audio koppelen aan lichtintensiteit was redelijk makkelijk, Blender heeft een ingebouwde functie om audio direct om te zetten in keyframes, dit werkt redelijk maar geeft je weinig controle.

Voor het besturen van de beweging wilde ik geluidsintensiteit koppelen aan de snelheid van de rotatie van de volumetric shader, dit kan niet met de methode die hierboven staat dus hier moest ik zelf een script voor schrijven.

Het besturen van shader waarden en het maken van keyframes ging redelijk vloeiend met de Blender API maar het grootste probleem kwam toen ik een WAV bestand om wou zetten naar volumewaardes en keyframes. Blender gebruikt helaas een andere versie van Python dan de OS en er is nog geen manier om externe python modules te installeren (trust me I tried). Ik moest dus een python script buiten blender runnen die met de soundfile module een wav file omzet in een csv bestand, dit kon ik lezen vanuit blender met de standard ingebouwde csv module en dit kon ik dan omzetten in volume en keyframes.

Blender kan heel veel maar als je iets wil doen wat buiten de verwachtte functionaliteit van Blender ligt is het ineens veel moeilijker of onmogelijk.


## De proof of concept 

Uiteindelijk heb ik 2 videos gemaakt, met het zelfde systeem en script als basis.

Nog een nadeel van Blender: In totaal duurde het renderen van de 16 seconden video's ongeveer 4 uur (tests niet meegerekend), in 1000x1000 pixels en met 12 samples-per-pixel, dit is nog redlijk lage kwaliteit, een hoge kwaliteit video duurt nog zeker 4x zo lang.

Ik heb de video's los gerendered en tot 1 video geëdit, ook met Blender. Had ik al verteld dat Blender veel kon?