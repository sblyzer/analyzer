import argparse
import subprocess
import sys
import time

def Main(argv):
  print('Build started.')

  subprocess.Popen('gn gen ./build').wait()
  parser = argparse.ArgumentParser

  success = True
  if not success:
    print('Build successfully.')
  else:
    print('Build failure.')

  return 0

if __name__ == '__main__':
  sys.exit(Main(sys.argv))
