# Blender opdracht voor visuals opdracht CSD2D

> LET OP! Ik heb de opdracht net anders geïnterpreteerd, met toestemming.


Voor de (Realtime) Visuals bij Muziek opdracht heb ik besloten om Blender te gebuiken vanwege de vele rendermogelijkheden, met als doel om te kijken of Blender geschikt is voor het maken van audio reactieve visuals.

---

Om een beeld te krijgen van de mogelijkheden in Blender heb ik een kort onderzoekje gedaan, zie [het document](BlenderMogelijkhedenOnderzoekje.pdf).

## Het plan

Ik heb al eerder gekeken naar realtime visuals in p5, three.js en game-engines zoals Unity en ik wou deze keer wat anders doen dus ik ga dit project gebruiken om offline visuals genereren met de Blender API en Shader Nodes.

* De vormen ga ik genereren met Volumetric Shader Nodes in Blender, dit creëert een ruimte binnen een object waarin je met textures vormen kan genereren.

* Ik ga een (kort) stukje muziek/geluid maken met veel dynamisch verschil om het effect duidelijk te laten zien.

* Met behulp van de Python Blender API ga ik parameters zoals lichtintensiteit en beweging van de vormen aansturen op basis van de hardheid van het geluid

* Ik wil met al deze dingen gaan expirimenteren en een aantal renders maken als een proof of concept

## MVP

Het eindresultaat moet minstens bevatten:
* Coole vormen gemaakt met Shader Nodes (minstens 2 korte filmpjes)
* Een Python script dat een audio bestand inlaad, de hardheid berekend en dit naar parameter keyframes schrijft.
* Documentatie over mijn bevingingen en conclusies