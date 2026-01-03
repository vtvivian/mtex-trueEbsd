   function [hash] = githash(fname, gitdir)
   % The following MATLAB function githash will return the hash of the last
   %  commit that modified the file in fname. If not provided with fname (use fname = '.') it
   %  returns the hash of the last commit in the repository.
   % Deepak Cherian | 19 Jan 2017
   % https://cherian.net/posts/reproducible-research-1.html
   % CC-BY-4.0 https://creativecommons.org/licenses/by/4.0/
   % VT 2025-12-15: modified to take string inputs (convert to chars)
   % and add '/.git' subfolder to gitdir

       if ~exist('fname', 'var')
           fname = '.';
       else
           fname = char(fname);
       end

       if ~exist('gitdir', 'var')
           gitdir = '';
       else
           gitdir = ['--git-dir=' char(gitdir) '/.git'];
       end

       [~, hashout] = system(['TERM=xterm git ' gitdir ...
                           ' log -n 1 --no-color --pretty=format:''%H'' ''' ...
                           fname ''' < /dev/null']);

       % remove bash escape characters
       hash = hashout(9:48);
   end