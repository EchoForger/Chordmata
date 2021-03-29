# Chordmata White Paper

The white paper describes the internal implementation of *Chordmata*.

## Class

### MIDIEvent

A MIDI event is a note which can tell the synthesizer the tune is and the maintain time.

#### Properties

| Property        | Describe                      |
| --------------- | ----------------------------- |
| int tune        | The tune of the note          |
| double maintain | The maintain time of the note |

#### Public Functions

| Function | Describe |
| -------- | -------- |
|          |          |
|          |          |
|          |          |

## Archive File

*Chordmata* save a `.chpoj` file as its project file where the infomation of this project saves. A  `.chpoj` file is actually a `.zip` file, unzipping which can get a folder. The content of the folder is described below:

```
.
├── ProjectInfo.json
└── Resource
    ├── Midi
    │   ├── 000.mid
    │   └── 001.mid
    └── Sample
        ├── 000.wav
        ├── 001.wav
        ├── 002.wav
        └── 003.wav
```

- **ProjectInfo.json**

  In this `.json` File, all of the matadate infomation are wtitten in the fomat discribed below:

  ```json
  [
      {
          "Name": "Hotel California",
          "Author": "The Eagles"
      }
  ]
  ```

- **Resource**

  All of the resources are settled in this folder.

- **MIDI**

  MIDI file,  which is like a music score, records the playing sequence of each instrument. It is numbered from 000.

- **Sample**

  Samples are stored as `.wav` files.

