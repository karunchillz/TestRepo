import cv

vidFile = cv.CaptureFromFile( '/home/mhughes/sintel_trailer-480p.mp4' )

nFrames = int(  cv.GetCaptureProperty( vidFile, cv.CV_CAP_PROP_FRAME_COUNT ) )
fps = cv.GetCaptureProperty( vidFile, cv.CV_CAP_PROP_FPS )
waitPerFrameInMillisec = int( 1/fps * 1000/1 )

print 'Num. Frames = ', nFrames
print 'Frame Rate = ', fps, ' frames per sec'

for f in xrange( nFrames ):
  frameImg = cv.QueryFrame( vidFile )
  cv.ShowImage( "My Video Window",  frameImg )
  cv.WaitKey( waitPerFrameInMillisec  )

# When playing is done, delete the window
#  NOTE: this step is not strictly necessary, 
#         when the script terminates it will close all windows it owns anyways
cv.DestroyWindow( "My Video Window" )
