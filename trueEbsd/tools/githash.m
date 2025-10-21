   function [hash] = githash(fname, gitdir)
   % The following MATLAB function githash will return the hash of the last
   %  commit that modified the file in fname. If not provided with fname it
   %  returns the hash of the last commit in the repository.
   % Deepak Cherian | 19 Jan 2017
   % https://cherian.net/posts/reproducible-research-1.html
   % CC-BY-4.0 https://creativecommons.org/licenses/by/4.0/

       if ~exist('fname', 'var')
           fname = '.';
       end

       if ~exist('gitdir', 'var')
           gitdir = '';
       else
           gitdir = ['--git-dir=' gitdir];
       end

       [~, hashout] = system(['TERM=xterm git ' gitdir ...
                           ' log -n 1 --no-color --pretty=format:''%H'' ''' ...
                           fname ''' < /dev/null']);

       % remove bash escape characters
       hash = hashout(9:48)
   end