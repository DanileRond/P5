from os import path
from pydub import AudioSegment

# files                                                                         
src = "ringtones-old-telephone.mp3"
dst = "old-telephone.wav"

# convert wav to mp3                                                            
sound = AudioSegment.from_mp3(src)
sound.export(dst, format="wav")
